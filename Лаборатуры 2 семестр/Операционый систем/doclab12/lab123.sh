#!/bin/bash
tar -cf 8.tar $@
tar -cf 8l.tar
find $@ -mtime -7 -exec tar -rf 8l.tar '{}' ';'

