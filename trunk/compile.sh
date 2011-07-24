#!/bin/bash
PARSED_ARGS=`getopt -u -o hmg:o: -l help,multitask,generate-only:,output: -- $@`

function usage {
    echo "Losak Compiler. Usage:"
    echo "    ./compile.sh (-h | --help)             Print this help message."
    echo "    ./compile.sh <OPTIONS> (- | <SOURCE>)  Compile <SOURCE>, where <OPTIONS> can be:"
    echo "        -g | --generate-only <C_SOURCE>    Generate C code, but not the binary."
    echo "        -o | --output <DESTINATION>        The compiler output file."
    echo "        -m | --multitask                   Use the support for language-level threads."
}

GENERATED_SOURCE='main.c'
if [ $? ]; then
    for ARG in ${PARSED_ARGS}; do
        if [[ -n "${PARSING_DESTINATION}" ]]; then
            DESTINATION="${ARG}"
            PARSING_DESTINATION=''
        elif [[ -n "${PARSING_GENERATED_SOURCE}" ]]; then
            GENERATED_SOURCE="${ARG}"
            PARSING_GENERATED_SOURCE=''
        elif [[ "${ARG}" == "-h" ]] || [[ "${ARG}" == "--help" ]]; then
            usage
            exit 0
        elif [[ "${ARG}" == "-m" ]] || [[ "${ARG}" == "--multitask" ]]; then
            MULTITASK='Yes'
        elif [[ "${ARG}" == "-g" ]] || [[ "${ARG}" == "--generate-only" ]]; then
            PARSING_GENERATED_SOURCE='Yes'
            GENERATE_ONLY='Yes'
        elif [[ "${ARG}" == "-o" ]] || [[ "${ARG}" == "--output" ]]; then
            PARSING_DESTINATION='Yes'
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
    if [[ -n "${MULTITASK}" ]]; then
        ./bin/desugar | ./bin/standard-library | ./bin/symbol-table | ./bin/multitask | ./bin/lambda-lift | ./bin/compiler > ${GENERATED_SOURCE}
    else
        ./bin/desugar | ./bin/standard-library | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > ${GENERATED_SOURCE}
    fi
else
    if [[ -n "${MULTITASK}" ]]; then
        ./bin/desugar < ${SOURCE} | ./bin/standard-library | ./bin/symbol-table | ./bin/multitask | ./bin/lambda-lift | ./bin/compiler > ${GENERATED_SOURCE}
    else
        ./bin/desugar < ${SOURCE} | ./bin/standard-library | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > ${GENERATED_SOURCE}
    fi
fi
if [[ -z "${GENERATE_ONLY}" ]]; then
    if [[ -n "${DESTINATION}" ]]; then
        gcc *.c -o "${DESTINATION}"
    else
        gcc *.c
    fi
fi
