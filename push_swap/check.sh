#!/usr/bin/env bash

ARG="1 2 3 22 888 78 81 10 12222 99 11 23" bash -c './push_swap $ARG | ./checker_linux $ARG'
