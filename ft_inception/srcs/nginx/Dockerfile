#Pulls base container image;
FROM debian:buster

#Installs base dependencies
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update > /dev/null && apt-get -y upgrade > /dev/null

RUN apt-get -y install \
nginx			\
openssl			\
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
-subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=Madrid/CN=www.42madrid.com"

#Copy configuration files and run.sh

COPY ./srcs/localhost /etc/nginx/sites-available/localhost
COPY ./srcs/index.html  /var/www/html/
COPY ./srcs/nginx.conf /etc/nginx

#Opens ports
EXPOSE 443

RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/ && \
rm /etc/nginx/sites-enabled/default



#Command with which the container is initializated
ENTRYPOINT service nginx start