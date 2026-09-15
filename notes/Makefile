PANDOC ?= pandoc
OUTPUT := build/algorithm-templates.pdf
CHAPTERS := $(sort $(wildcard chapters/*.md))

.PHONY: pdf clean

pdf: $(OUTPUT)

$(OUTPUT): metadata.yaml pandoc.yaml filters/callouts.lua tex/header.tex $(CHAPTERS) | build
	$(PANDOC) --defaults=pandoc.yaml

build:
	mkdir -p $@

clean:
	rm -f $(OUTPUT)
