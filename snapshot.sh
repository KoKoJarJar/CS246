#!/bin/bash

info() { printf "%s\n" "$*" >&2; }
export BORG_PASSPHRASE=PashmakeAbi91
export BORG_REPO=~/Backup
if [ ${#} -lt 1 ]; then
  info "Enter a valid time"
  exit 1
fi
backup_time=$1
backup_seconds=$( date -d "${backup_time}" "+%s" 2>/dev/null)
if [ ${?} -gt 0 ]; then
  info "Not a valid time"
  exit 1
fi
working_directory="$( pwd | sed -E "s:(/)(.*):\2:" )"
backup_dates="$( borg list "${BORG_REPO}")"
correct_time="$( echo "${backup_dates}" | awk '{print$1" "$1}' | \
  sed -E "s:(.+) ([^0-9]+)-([0-9]+):\1 \3:" | \
  sed -E "s:(.+) (.+):echo -n \1 \$( date -d \2 \"+%s\"):e" | \
  sed -E "s:(.+) (.*):echo -n \1 \$((\2 - ${backup_seconds})):e" | \
  egrep ".+ -.*" | sort -nr -k2 | head -1 | sed -E "s:(.+) (.*):\1:" )"
if [ "${correct_time}" = "" ]; then
  info "No previous backup for time specified"
  exit 1
fi
if [ "$( borg list "${BORG_REPO}::${correct_time}" | \
  egrep "${working_directory}$" )" = "" ]; then
  info "The current directory does not exist as a back up"
  exit 1
fi
directory_path="$( pwd )/borg_extract_$( date "+%s" )"
mkdir -p "${directory_path}"
cd "${directory_path}"
borg extract "${BORG_REPO}::${correct_time}" "${working_directory}"
cd "${directory_path}/${working_directory}"
cp -pr * "/${working_directory}"
rm -rf "${directory_path}"
exit 0
