SRC = ./src/docker-compose.yml

all:
	docker-compose -f $(SRC) up -d --build

clean:
	docker-compose -f $(SRC) down

fclean:
	docker-compose -f $(SRC) down --rmi all
	docker volume rm src_mariadb_volume src_wordpress_volume