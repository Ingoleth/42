if [ "$AUTOINDEX" = "on" ] ;
then cp /tmp/localhost_ai /etc/nginx/sites-available/localhost;
else cp /tmp/localhost /etc/nginx/sites-available/localhost;
fi
cp /tmp/index.html /var/www/html/
service nginx reload