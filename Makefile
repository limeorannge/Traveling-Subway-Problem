.PHONY: all generate-data build run pretty validate clean

all: generate-data build

# Generate the compact data used by the solver
generate-data:
	cd src && python3 data_former.py

# Compile the C++ solver
build:
	cd src && g++ -std=c++17 -O2 solver.cpp -o solver

# Run the solver and save stdout to `src/result.txt`
run:
	cd src && ./solver > result.txt

# Pretty-print the solver's `result.txt` using the data_former.py re-formatter
pretty:
	cd src && python3 data_former.py

# Quick validations
validate:
	@test -f data/data.txt || (echo "data/data.txt missing — run 'make generate-data'" && exit 1)
	@echo "data/data.txt exists"

clean:
	rm -f src/solver src/result.txt
