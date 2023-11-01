#!/usr/bin/env bash

ARG="1 2 3 4 3" bash -c './push_swap $ARG | ./checker_linux $ARG'
