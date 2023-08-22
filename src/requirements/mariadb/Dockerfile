FROM debian:buster

COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh
ENTRYPOINT ["/setup.sh"]
CMD ["mysqld"]