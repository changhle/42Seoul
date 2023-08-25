COMPOSE = ./src/docker-compose.yml

all:
	docker-compose -f $(COMPOSE) up -d --build

clean:
	docker-compose -f $(COMPOSE) down

fclean:
	docker-compose -f $(COMPOSE) down --rmi all
	docker volume rm mariadb_volume wordpress_volume

re:
	make fclean
	make all

.PHONY: all clean fclean re