<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'ft_server' );

/** MySQL database password */
define( 'DB_PASSWORD', 'Password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

$table_prefix = 'wp_';

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'U8t]/h6P24X:wj)xC^`zEJ<>@lyh2KnYuEw_t~VZUQ,*/%im|;r8p{AOx)0(8Jwv' );
define( 'SECURE_AUTH_KEY',  ')DFE+=w-_b?lrbB%hXAE1iO#+Sz|s=S0Nl5qT~x(Vxh8>|<W7-28~V_zLqF@![t ' );
define( 'LOGGED_IN_KEY',    '=p$iC2lIZBH!<)gy =wxNcIC%5aKUAmBKN)&/`o][lf<(881J~js`(KBR0((?lvB' );
define( 'NONCE_KEY',        'VC:TQ*4iXT_zUC{mN;Dd+=:Bq/Xk7^ToNNO9nkYpMGe[o,994q;([K.Xdh7H34PB' );
define( 'AUTH_SALT',        ';Cnn6|JZz;hXh8|cG87QP-p2.>qvH5)YbvFn0=ltlEi;C55;!pAEf-7x#di3{~,#' );
define( 'SECURE_AUTH_SALT', 'u66-}XYQ&^Q}H(ab(/iXKd;qNMv W+$=iE&|.%_`5{)_Hf{P!xWF#^7JpHzO:1#u' );
define( 'LOGGED_IN_SALT',   'YM9Gi(!5)%VeTr`S%wO<)*!m,z)P>(D]yA!YZUhXdfq:GS+C/fw#r# yrsVcHbhR' );
define( 'NONCE_SALT',       'Yt)StX87jq1>KORtBCPXs_N,;!38S<]*&@Ib>vI@+OJ+6G?n w]K0gA5brZy=}J8' );

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
