if [ "$AUTOINDEX" = "off" ] ;
then cp /tmp/localhost /etc/nginx/sites-available/localhost;
else cp /tmp/localhost_ai /etc/nginx/sites-available/localhost;
fi
service nginx reload