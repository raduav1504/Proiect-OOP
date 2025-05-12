#!/usr/bin/bash

CPPCHECK_INCLUDE="-I ${PWD}/include"

cppcheck \
    ${CPPCHECK_INCLUDE} \
    --enable=all \
    --inline-suppr \
    --project="${BUILD_DIR:-build}"/compile_commands.json \
    -i"${BUILD_DIR:-build}"   --suppress="*:${BUILD_DIR:-build}/*" \
    -i"${EXT_DIR:-ext}"       --suppress="*:${EXT_DIR:-ext}/*" \
    -i"${GEN_DIR:-generated}" --suppress="*:${GEN_DIR:-generated}/*" \
    --suppress=missingIncludeSystem \
    --suppress=missingInclude \
    --suppress=unmatchedSuppression \
    --suppress=useStlAlgorithm \
    --check-level=exhaustive \
    --error-exitcode=1
