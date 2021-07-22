
FROM debian:buster

# UPDATE_PACKAGE
RUN apt-get update;\
		apt-get upgrade -y

# INSTALL_NGINX_PHP_MARIADB_WGET_VIM
RUN apt-get install -y nginx;\
		apt-get install -y php7.3 php-fpm php-mysql php-gd php-mbstring;\
		apt-get install -y mariadb-server;\
		apt-get install -y wget;\
		apt-get install -y vim

# WORDPRESS_DOWNLOAD
RUN wget https://wordpress.org/latest.tar.gz;\
		tar -xvzf latest.tar.gz

# PHPMYADMIN_DOWNLOAD
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz;\
		tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz

# REMOVE_
RUN rm var/www/html/index.nginx-debian.html;\
		mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpMyAdmin;\
		rm phpMyAdmin-4.9.0.1-all-languages.tar.gz

RUN mv wordpress /var/www/html/wordpress;\
		chown -R www-data:www-data /var/www/html/wordpress/;\
		chmod -R 755 /var/www/html/wordpress/;\
		rm latest.tar.gz

RUN openssl req -x509 -nodes -days 3650 -newkey rsa:2048 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42" -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt

COPY ./srcs/php.ini ./etc/php/7.3/fpm/php.ini
COPY ./srcs/default ./etc/nginx/sites-available/default
COPY ./srcs/wordpress ./etc/nginx/sites-available/wordpress
COPY ./srcs/info.php ./var/www/html
COPY ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
#COPY ./srcs/localhost.crt /etc/ssl/certs/localhost.crt
#COPY ./srcs/localhost.key /etc/ssl/private/localhost.key
COPY ./srcs/init_wordpress init_wordpress
COPY ./srcs/service.sh service.sh
COPY ./srcs/init.sh init.sh
COPY ./srcs/container_start.sh container_start.sh

RUN sh init.sh

CMD ["bash", "./container_start.sh"]
