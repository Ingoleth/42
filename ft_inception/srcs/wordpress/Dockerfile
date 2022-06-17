#Pulls base container image;
FROM debian:buster

#Installs base dependencies
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update > /dev/null && apt-get -y upgrade > /dev/null

RUN apt-get -y install \
php-fpm			\
php-mysql		\
wget			\
> /dev/null

# Sets php-fpm configuration to listen on port 9000
RUN sed 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/' -i /etc/php/7.3/fpm/pool.d/www.conf

#Wordpress management
COPY srcs/wp-cli.phar /usr/bin/wp
COPY srcs/entrypoint.sh /
COPY srcs/latest.tar.gz /

RUN mkdir -p /var/run/php

#Opens ports
EXPOSE 9000

#Command with which the container is initializated
ENTRYPOINT ["bash", "/entrypoint.sh"]
