#!/bin/bash

echo "Start FIFO"
sudo ./Sched F

echo "Start RoundRobin"
sudo ./Sched R

echo "Start DeadLine"
sudo ./Sched D
