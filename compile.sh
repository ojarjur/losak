#!/bin/bash
COMPILE=$0
PARSED_ARGS=`getopt -u -o hbmd:g:o: -l help,bare-hardware,multitask,debug-dir:,generate-only:,output: -- $@`

usage () {
    echo "Losak Compiler."
    echo "Usage: ${COMPILE} <OPTIONS> (- | <SOURCE>)"
    echo "Options:"
    echo "  -h | --help                      Print this message and exit."
    echo "  -g | --generate-only <C_SOURCE>  Generate C code, but not the binary."
    echo "  -o | --output <DESTINATION>      The compiler output file."
    echo "  -d | --debug-dir <DIRECTORY>     Save the intermediate steps of compilation in the given dir."
    echo "  -b | --bare-hardware             Target running on bare hardware (with no underlying OS)."
    echo "  -m | --multitask                 Use the support for language-level threads."
}

INSTALL_DIR="."
CPS_TRANSFORM="${INSTALL_DIR}/bin/cps-transform"
#CPS_TRANSFORM='cat'
CC_FLAGS="-pipe -I ${INSTALL_DIR}/include ${INSTALL_DIR}/include/*.c -x c -"
if [ $? ]; then
    for ARG in ${PARSED_ARGS}; do
        if [[ -n "${PARSING_DESTINATION}" ]]; then
            DESTINATION="${ARG}"
            PARSING_DESTINATION=''
        elif [[ -n "${PARSING_GENERATED_SOURCE}" ]]; then
            GENERATED_SOURCE="${ARG}"
            PARSING_GENERATED_SOURCE=''
        elif [[ -n "${PARSING_DEBUG_DIR}" ]]; then
            DEBUG_DIR="${ARG}"
            PARSING_DEBUG_DIR=''
        elif [[ "${ARG}" == "-g" ]] || [[ "${ARG}" == "--generate-only" ]]; then
            PARSING_GENERATED_SOURCE='Yes'
            GENERATE_ONLY='Yes'
        elif [[ "${ARG}" == "-o" ]] || [[ "${ARG}" == "--output" ]]; then
            PARSING_DESTINATION='Yes'
        elif [[ "${ARG}" == "-d" ]] || [[ "${ARG}" == "--debug-dir" ]]; then
            PARSING_DEBUG_DIR='Yes'
            DEBUG='Yes'
        elif [[ "${ARG}" == "-h" ]] || [[ "${ARG}" == "--help" ]]; then
            usage
            exit 0
        elif [[ "${ARG}" == "-m" ]] || [[ "${ARG}" == "--multitask" ]]; then
            CPS_TRANSFORM="${INSTALL_DIR}/bin/multitask"
        elif [[ "${ARG}" == "-b" ]] || [[ "${ARG}" == "--bare-hardware" ]]; then
            CC_FLAGS="${INSTALL_DIR}/include/boot.S ${CC_FLAGS}"
            LD_FLAGS="-m elf_i386 -dN -Ttext 0x100000 -e start"
            CC_FLAGS="$(for FLAG in `echo ${LD_FLAGS}`; do echo -Xlinker $FLAG; done) ${CC_FLAGS}"
            CC_FLAGS="-nostdlib -nostartfiles -nodefaultlibs -nostdinc -static ${CC_FLAGS}"
            CC_FLAGS="-m32 -ffreestanding -DBARE_HARDWARE ${CC_FLAGS}"
            CPS_TRANSFORM="${INSTALL_DIR}/bin/multitask"
        elif [[ "${ARG}" != "--" ]]; then
            SOURCE="${ARG}"
        fi
    done
else
    usage
    exit 1
fi
if [[ -z "${SOURCE}" ]] || [[ -n "${PARSING_GENERATED_SOURCE}" ]] || [[ -n "${PARSING_DESTINATION}" ]] || [[ -n "${PARSING_DEBUG_DIR}" ]]; then
    usage
    exit 1
fi
if [[ "${SOURCE}" == "-" ]]; then
    SOURCE='/dev/stdin'
fi
C_SOURCE=`${INSTALL_DIR}/bin/desugar < ${SOURCE} | ${INSTALL_DIR}/bin/standard-library | ${INSTALL_DIR}/bin/symbol-table | ${CPS_TRANSFORM} | ${INSTALL_DIR}/bin/lambda-lift | ${INSTALL_DIR}/bin/codegen`
if [[ -n "${DEBUG}" ]]; then
    C_SOURCE=`${INSTALL_DIR}/bin/desugar < ${SOURCE} | tee ${DEBUG_DIR}/desugar-output.lsk | ${INSTALL_DIR}/bin/standard-library | tee ${DEBUG_DIR}/standard-library-output.lsk | ${INSTALL_DIR}/bin/symbol-table | tee ${DEBUG_DIR}/symbol-table-output.lsk | ${CPS_TRANSFORM} | tee ${DEBUG_DIR}/cps-transform-output.lsk | ${INSTALL_DIR}/bin/lambda-lift | tee ${DEBUG_DIR}/lambda-lift-output.lsk | ${INSTALL_DIR}/bin/codegen`
fi
if [[ -z "${GENERATE_ONLY}" ]]; then
    if [[ -n "${DESTINATION}" ]]; then
        CC_FLAGS="-o ${DESTINATION} ${CC_FLAGS}"
    fi
    echo "${C_SOURCE}" | gcc ${CC_FLAGS}
else
    echo "${C_SOURCE}" > ${GENERATED_SOURCE}
fi
