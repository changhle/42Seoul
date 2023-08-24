FROM debian:buster

RUN	apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install \
	mariadb-server \
	vim

RUN	sed -i "s/bind-address/#bind-address/" /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh
ENTRYPOINT ["/setup.sh"]