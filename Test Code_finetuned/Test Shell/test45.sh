#!/bin/bash

# Step 1: Extract lines from the C source file that start with "///"
grep '^///' discheme.c |

# Step 2: Remove the "///" prefix and any leading spaces
sed's/^\/\/\///' |

# Step 3: Redirect the formatted comments to a new file
> discheme.adoc

# Step 4: Convert the discheme.adoc file to a documentation file
asciidoctor discheme.adoc