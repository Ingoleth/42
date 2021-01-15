
#!/bin/bash
PASS=Password
USER=ft_server
DATABASE=wordpress
service mysql start
mysql -uroot <<MYSQL_SCRIPT
CREATE DATABASE $DATABASE;
CREATE USER '$USER'@'localhost' IDENTIFIED BY '$PASS';
GRANT ALL PRIVILEGES ON $DATABASE.* TO '$USER'@'localhost';
FLUSH PRIVILEGES;
MYSQL_SCRIPT

echo "MySQL user created."
echo "Username:   $USER"
echo "Password:   $PASS"
mysql wordpress -u ft_server -p$PASS < /wordpress.sql