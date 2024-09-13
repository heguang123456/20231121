make:
	make -C ./src/
	mv ./src/process_copy ./
	make -C ./mod/

clean:
	rm ./process_copy
	rm ./mod/copy
	make clean -C ./src
	make clean -C ./mod
