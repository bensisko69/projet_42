#!/usr/bin/php
<?PHP
    setlocale(LC_ALL, 'fr_FR');
    date_default_timezone_set('Europe/Paris');

    $my_date = strptime($argv[1], "%A %e %B %Y %T");
    if ($my_date == null)
        echo "Wrong Format\n";
    else
    {
        echo mktime($my_date["tm_hour"],
                    $my_date["tm_min"],
                    $my_date["tm_sec"],
                    $my_date["tm_mon"] + 1,
                    $my_date["tm_mday"],
                    $my_date["tm_year"] + 1900);
        echo "\n";
    }
?>