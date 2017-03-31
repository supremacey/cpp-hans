all: rational stack

rational:
	@echo "\n--- rational.out --------------------"
	cd code02; make 
	-cp code02/main.out ./rational.out

stack:
	@echo "\n--- stack.out -----------------------"
	cd code03; make
	-cp code03/main.out ./stack.out

clean:
	@echo "\n--- clean ---------------------------"
	cd code02; make clean
	cd code03; make clean
	rm -f rational.out stack.out

.PHONY: clean stack rational
