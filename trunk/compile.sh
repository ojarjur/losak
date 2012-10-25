#!/bin/bash
PARSED_ARGS=`getopt -u -o hbmg:o: -l help,bare-hardware,multitask,generate-only:,output: -- $@`

function usage {
    echo "Losak Compiler. Usage:"
    echo "    ./compile.sh (-h | --help)             Print this help message."
    echo "    ./compile.sh <OPTIONS> (- | <SOURCE>)  Compile <SOURCE>, where <OPTIONS> can be:"
    echo "        -g | --generate-only <C_SOURCE>    Generate C code, but not the binary."
    echo "        -o | --output <DESTINATION>        The compiler output file."
    echo "        -b | --bare-hardware               Target running on bare hardware (with no underlying OS)."
    echo "        -m | --multitask                   Use the support for language-level threads."
}

GENERATED_SOURCE='main.c'
#CPS_TRANSFORM='./bin/cps-transform'
CPS_TRANSFORM='cat'
CC_FLAGS='-pipe -I include include/*.c -x c -'
if [ $? ]; then
    for ARG in ${PARSED_ARGS}; do
        if [[ -n "${PARSING_DESTINATION}" ]]; then
            DESTINATION="${ARG}"
            PARSING_DESTINATION=''
        elif [[ -n "${PARSING_GENERATED_SOURCE}" ]]; then
            GENERATED_SOURCE="${ARG}"
            PARSING_GENERATED_SOURCE=''
        elif [[ "${ARG}" == "-g" ]] || [[ "${ARG}" == "--generate-only" ]]; then
            PARSING_GENERATED_SOURCE='Yes'
            GENERATE_ONLY='Yes'
        elif [[ "${ARG}" == "-o" ]] || [[ "${ARG}" == "--output" ]]; then
            PARSING_DESTINATION='Yes'
        elif [[ "${ARG}" == "-h" ]] || [[ "${ARG}" == "--help" ]]; then
            usage
            exit 0
        elif [[ "${ARG}" == "-m" ]] || [[ "${ARG}" == "--multitask" ]]; then
            CPS_TRANSFORM='./bin/multitask'
        elif [[ "${ARG}" == "-b" ]] || [[ "${ARG}" == "--bare-hardware" ]]; then
            CC_FLAGS="-Xlinker -m -Xlinker elf_i386 -Xlinker -dN -Xlinker -Ttext -Xlinker 0x100000 -Xlinker -e -Xlinker start include/boot.S ${CC_FLAGS}"
            CC_FLAGS="-nostdlib -nostartfiles -nodefaultlibs -nostdinc -static ${CC_FLAGS}"
            CC_FLAGS="-m32 -ffreestanding -DBARE_HARDWARE ${CC_FLAGS}"
            CPS_TRANSFORM='./bin/multitask'
        elif [[ "${ARG}" != "--" ]]; then
            SOURCE="${ARG}"
        fi
    done
else
    usage
    exit 1
fi
if [[ -z "${SOURCE}" ]] && [[ -z "${GENERATED_SOURCE}" ]]; then
    usage
    exit 1
fi
if [[ "${SOURCE}" == "-" ]]; then
    SOURCE='/dev/stdin'
fi
C_SOURCE=`./bin/desugar < ${SOURCE} | ./bin/standard-library | ./bin/symbol-table | ${CPS_TRANSFORM} | ./bin/lambda-lift | ./bin/compiler`
if [[ -z "${GENERATE_ONLY}" ]]; then
    if [[ -n "${DESTINATION}" ]]; then
        CC_FLAGS="-o ${DESTINATION} ${CC_FLAGS}"
    fi
    echo "${C_SOURCE}" | gcc ${CC_FLAGS}
else
    echo "${C_SOURCE}" > ${GENERATED_SOURCE}
fi
