#!/usr/bin/env bash

# Build the dev image if it does not exist already
if ! docker inspect lemin-dev &> /dev/null ; then
    docker build -t lemin-dev -f Dockerfile.dev .
fi

docker run --rm -v $1:/lemin -w /lemin lemin-dev make
