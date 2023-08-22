FROM debian:buster

COPY ./tools/setup.sh /setup.sh
COPY ./conf/default /var/www/html/default
RUN chmod +x /setup.sh
ENTRYPOINT ["/setup.sh"]
CMD ["nginx", "-g", "daemon off;"]
# CMD ["service", "nginx", "start"]