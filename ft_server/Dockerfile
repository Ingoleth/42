#Pulls base container image;
FROM debian:buster

#Installs base dependencies
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update > /dev/null && apt-get -y upgrade > /dev/null && apt-get -y install \
php-fpm			\
php-mysql		\
php-cli			\
php-mbstring	\
php-zip			\
php-gd			\
nginx			\
mariadb-server	\
openssl			\
wget			\
> /dev/null

#Generate self-signed certificate

RUN mkdir /etc/nginx/ssl; \
openssl req -newkey rsa:4096 \
-x509 \
-sha256 \
-days 3650 \
-nodes \
-out /etc/ssl/certs/localhost.pem \
-keyout /etc/ssl/private/localhost-key.pem \
-subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=Madrid/CN=www.42marid.com"

#Wordpress management
RUN (cd tmp; wget https://wordpress.org/latest.tar.gz; tar xf latest.tar.gz -C ../var/www/html)

#Php_my_admin management
RUN mkdir /var/www/html/phpmyadmin && \
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz; \
tar xf phpMyAdmin-5.0.4-english.tar.gz --strip-components 1 -C /var/www/html/phpmyadmin

#Copy configuration files and run.sh

COPY ./srcs/localhost /tmp
COPY ./srcs/localhost_ai /tmp
COPY ./srcs/nginx.sh /tmp
COPY ./srcs/index.html  /tmp
COPY ./srcs/run.sh /
COPY ./srcs/nginx.conf /etc/nginx
COPY ./srcs/mysql.sh /
COPY ./srcs/wp-config.php /var/www/html/wordpress
COPY ./srcs/wordpress.sql /

#Opens ports
EXPOSE 80 443 8081

ENV AUTOINDEX on

RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/ && \
rm /etc/nginx/sites-enabled/default && \
bash tmp/nginx.sh

#Command with which the container is initializated
CMD ["bash", "run.sh"]