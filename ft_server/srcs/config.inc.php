<?php
declare(strict_types=1);
$cfg['blowfish_secret'] = 'Ilikecookiescookiesarenicenyummy'; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */

/**
 * Servers configuration
 */
$i = 0;
$i++;
/* Authentication type */
$cfg['Servers'][$i]['auth_type'] = 'cookie';
/* Server parameters */
$cfg['Servers'][$i]['host'] = 'localhost';
$cfg['Servers'][$i]['compress'] = false;
$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
$cfg['Servers'][$i]['ssl'] = true;
$cfg['Servers'][$i]['ssl_key'] = '/etc/nginx/ssl/localhost-key.pem';