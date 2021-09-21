#!/bin/sh
echo script started

while true; do
    while true; do
        if ln ./file ./file.lock 2>/dev/null; then
            break
        fi
    done
    echo $(($(tail -1 <./file) + 1)) >> ./file
    rm ./file.lock
done

