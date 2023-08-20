SRC = ./src/docker-compose.yml

all:
	docker-compose -f $(SRC) up -d --build

clean:
	docker-compose -f $(SRC) down