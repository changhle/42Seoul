#!/bin/bash

apt-get -y update
apt-get -y upgrade
apt-get -y install \
mariadb-server \
vim

sed -i "s/bind-address/#bind-address/" /etc/mysql/mariadb.conf.d/50-server.cnf
# sed -i "s/password =/password = $MARIADB_ROOT_PWD/g" /etc/mysql/debian.cnf

service mysql start
# mysql -uroot -p$MARIADB_ROOT_PWD -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PWD}';"
mysql -uroot -p$MARIADB_ROOT_PWD -e "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;"
mysql -uroot -p$MARIADB_ROOT_PWD -e "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';"
# echo "CREATE USER IF NOT EXISTS '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
# echo "GRANT ALL PRIVILEGES ON mysql.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
mysql -uroot -p$MARIADB_ROOT_PWD -e "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';"
# echo "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
mysql -uroot -p$MARIADB_ROOT_PWD -e "FLUSH PRIVILEGES;"
service mysql stop

exec "$@"
