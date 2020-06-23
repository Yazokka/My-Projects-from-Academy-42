#!/bin/sh

echo 'apt-get update && apt-get upgrade >> /var/log/script_update.log' >> ~/.tempfile
echo '0 4 * * * root sh ~/.tempfile' | crontab
