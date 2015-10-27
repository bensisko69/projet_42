#! /usr/bin/env zsh
for f (test/*.eq) {xargs ./computor < $f | > $f+}