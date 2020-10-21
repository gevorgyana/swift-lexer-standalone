# Find files (.a/.so-suffixed) that have a regex-given symbol in them
# Set $pattern first
function found_in_file() {
    count=$(nm $1 | c++filt | grep -c $pattern)
    if [ "$count" -gt 0 ]; then
	echo $1
    fi
}

function try_files() {
    export -f found_in_file
    export pattern
    find . \( -name '*.a' -o -name 'foo' \)  -exec bash -c 'found_in_file "$0"' {} \;
}
