FROM debian:buster

RUN	apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install \
	mariadb-client \
	php7.3 \
	php-fpm \
	php-cli \
	curl \
	php-mysql \
	php-mbstring \
	php-xml \
	vim

RUN	sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.3/fpm/pool.d/www.conf

RUN	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh
ENTRYPOINT ["/setup.sh"]