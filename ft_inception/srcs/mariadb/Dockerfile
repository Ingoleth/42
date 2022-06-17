#Pulls base container image;
FROM debian:buster

RUN groupadd -r mysql && useradd -r -g mysql mysql

#Installs base dependencies
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update > /dev/null && apt-get -y upgrade > /dev/null

RUN apt-get -y install mariadb-server > /dev/null

RUN rm -rf /var/lib/mysql && mkdir -p /var/lib/mysql /var/run/mysqld \
&& chown -R mysql:mysql /var/lib/mysql /var/run/mysqld \
&& chmod 1777 /var/run/mysqld /var/lib/mysql

COPY srcs/entrypoint.sh /

#Opens ports
EXPOSE 3306

#Command with which the container is initializated
ENTRYPOINT [ "sh", "/entrypoint.sh" ]
