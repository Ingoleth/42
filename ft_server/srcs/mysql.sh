
#!/bin/bash
PASS=Password
USER_DB=ft_server
DATABASE=wordpress
service mysql start
mysql -uroot <<MYSQL_SCRIPT
CREATE DATABASE $DATABASE;
CREATE USER '$USER'@'localhost' IDENTIFIED BY '$PASS';
GRANT ALL PRIVILEGES ON $DATABASE.* TO '$USER'@'localhost';
FLUSH PRIVILEGES;
MYSQL_SCRIPT

echo "MySQL user created."
echo "Username:   $USER_DB"
echo "Password:   $PASS"
mysql wordpress -u $USER_DB -p$PASS < /wordpress.sql