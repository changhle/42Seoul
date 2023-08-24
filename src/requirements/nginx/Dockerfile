FROM debian:buster

RUN	apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install \
	nginx \
	openssl \
	vim

COPY ./tools/setup.sh /setup.sh
COPY ./conf/default /default
RUN chmod +x /setup.sh
ENTRYPOINT ["/setup.sh"]
CMD ["nginx", "-g", "daemon off;"]
# CMD ["service", "nginx", "start"]