#!/bin/bash

apt-get -y update
apt-get -y upgrade
apt-get -y install \
nginx \
openssl \
vim

openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/ssl/private/server_pkey.pem \
		-out /etc/ssl/certs/server.crt \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=./CN=changhle.42.fr/emailAddress=changhle@student.42seoul.kr"
yes | cp var/www/html/default /etc/nginx/sites-available/default

# service nginx start
exec "$@"
