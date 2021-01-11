docker build -t ft_server:latest .
printf "\n-----------\nImage built\n-----------\n\n"
docker run -d --name ft_server -p 80:80 -p 443:443 ft_server:latest