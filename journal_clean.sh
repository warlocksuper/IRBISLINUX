#!/bin/sh


journalctl --rotate
journalctl --vacuum-time=1s
