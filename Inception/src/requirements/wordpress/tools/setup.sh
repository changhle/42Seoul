#!/bin/bash

service php7.3-fpm start
if [ ! -f /var/www/html/wp-config.php ]; then
  cd
  wp core download --allow-root --path=/var/www/html/
  wp config create --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PWD --dbhost=$WORDPRESS_DB_HOST --dbprefix=wp_ --allow-root --path=/var/www/html/
  wp core install --url=https://$DOMAIN_NAME --title="Changhle's inception" --admin_user=$ADMIN_NAME --admin_password=$ADMIN_PWD --admin_email=$ADMIN_EMAIL --allow-root --path=/var/www/html/
  wp user create "$USER_NAME" "$USER_EMAIL" --role=subscriber --user_pass="$USER_PWD" --allow-root --path=/var/www/html/
  chown -R www-data:www-data /var/www/html
fi
service php7.3-fpm stop

/usr/sbin/php-fpm7.3 -F