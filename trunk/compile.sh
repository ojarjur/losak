#!/bin/bash
PARSED_ARGS=`getopt -u -o hmo: -l help,multitask,output: -- $@`

function usage {
    echo "Losak Compiler. Usage:"
    echo "    ./compile.sh (-h | --help)             Print this help message."
    echo "    ./compile.sh <OPTIONS> (- | <SOURCE>)  Compile <SOURCE>, where <OPTIONS> can be:"
    echo "        -o | --output <DESTINATION>        The compiler output file."
    echo "        -m | --multitask                   Use the support for language-level threads."
}

if [ $? ]; then
    for ARG in ${PARSED_ARGS}; do
        if [[ -n "${PARSING_DESTINATION}" ]]; then
            DESTINATION="${ARG}"
            PARSING_DESTINATION=''
        elif [[ "${ARG}" == "-h" ]] || [[ "${ARG}" == "--help" ]]; then
            usage
            exit 0
        elif [[ "${ARG}" == "-m" ]] || [[ "${ARG}" == "--multitask" ]]; then
            MULTITASK='Yes'
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
if [[ -z "${SOURCE}" ]]; then
    usage
    exit 1
fi
if [[ "${SOURCE}" == "-" ]]; then
    if [[ -n "${MULTITASK}" ]]; then
        ./bin/desugar | ./bin/symbol-table | ./bin/multitask | ./bin/lambda-lift | ./bin/compiler > main.c
    else
        ./bin/desugar | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > main.c
    fi
else
    if [[ -n "${MULTITASK}" ]]; then
        ./bin/desugar < ${SOURCE} | ./bin/symbol-table | ./bin/multitask | ./bin/lambda-lift | ./bin/compiler > main.c
    else
        ./bin/desugar < ${SOURCE} | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > main.c
    fi
fi
if [[ -n "${DESTINATION}" ]]; then
    gcc *.c -o "${DESTINATION}"
else
    gcc *.c
fi
