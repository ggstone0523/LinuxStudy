#!/bin/bash

watch -n 1 "ps -eo user,pid,cmd,%cpu --no-headers | grep task.sh"
