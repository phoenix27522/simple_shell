#!/bin/bash

OUTPUT_FILE="AUTHORS"

github_users=()

echo "# The following people wrote this simple_shell\n\n" > "$OUTPUT_FILE"

git shortlog -se \
  | perl -spe 's/^\s+\d+\s+//' \
  | sed -e '/^CommitSyncScript.*$/d' \
  | grep -oE '<[^>]*>' \
  | sed 's/[<>]//g' \
  | sed 's/[+]//g' \
  | sed 's/^[0-9]*//'\
  >> "$OUTPUT_FILE"

echo "List of people contributed to this repo has been generated and saved to $OUTPUT_FILE"
