build: 
	@bash build_in_docker.sh

docker:
	@docker build -t docker-sdl .

test:
	@bash test.sh


