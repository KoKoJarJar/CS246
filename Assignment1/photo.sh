#!/bin/bash
current_dir="$( pwd )"
cd ~
mkdir -p "public_html"
eval mv "${current_dir}/*.{gif,jpg,jpeg,GIF,JPG,JPEG}" "public_html" 2>/dev/null
chmod "a+rx" "public_html"
eval chmod "a+r" "public_html"
