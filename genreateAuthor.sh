#!/bin/bash

OUTPUT_FILE="AUTHORS"

github_users=()

echo "# The following people wrote this simple_shell" > "$OUTPUT_FILE"

echo "" >> "$OUTPUT_FILE"

# Use Git log to get a list of email addresses from the commit history
git shortlog -se \
  | perl -spe 's/^\s+\d+\s+//' \
  | sed -e '/^CommitSyncScript.*$/d' \
  | grep -oE '<[^>]*>' \
  | sed 's/[<>]//g' \
  | sed 's/[+]//g' \
  | sed 's/^[0-9]*//'\
  >> "$OUTPUT_FILE"

echo "List of people contributed to this repo has been generated and saved to $OUTPUT_FILE"
