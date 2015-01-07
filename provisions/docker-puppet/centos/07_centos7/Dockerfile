###############################################################################
# Provisionous Docker/Puppet profile
# OS: CentOS 7 (centos7)
# Equivalent: RHEL 7, Fedora 19 (schrodinger)
###############################################################################

FROM centos:centos7
MAINTAINER Luís Pedro Algarvio <lp.algarvio@gmail.com>

# Configure the enviroment
ENV TERM linux
RUN mkdir -p /root/setup;
WORKDIR /root/setup

#
# Package Management System initialization
#

# Clear and Update the PMS cache if it is outdated
#RUN ["/bin/bash", "-c", "if [ \
#  \"$(stat -c %Y /var/cache/yum/x86_64/7/timedhosts)\" -lt \
#  \"$(date +\"%s\" -d \"-3 days\")\" ] || \
#  [ -f /var/cache/yum/x86_64/7/timedhosts ]; \
#  then yum clean all; yum makecache; \
#  else echo \"Yum caches are up-to-date.\"; fi;"]
RUN yum clean all; yum makecache;

#
# System dependencies and upgrades
#

# Install system dependencies
RUN yum -y install yum-plugin-fastestmirror bash-completion which tar wget nano gnupg2 && \
    yum clean packages;

# Upgrade the packages
RUN yum -y upgrade && \
    yum clean packages;

#
# Repositories and GPG keys
#

# Update keys
RUN gpg2 --refresh-keys;

# SCL repo, for alternative releases - no support/centos5+7
#RUN yum -y install centos-release-SCL;

# EPEL repo, for extra packages
#RUN yum -y install epel-release;

# ELRepo key/repo, for updated kernel/drivers - install issues/centos5+6
#RUN wget -q http://www.elrepo.org/RPM-GPG-KEY-elrepo.org && \
#    gpg2 --import RPM-GPG-KEY-elrepo.org && \
#    rpm --import RPM-GPG-KEY-elrepo.org && \
#    rpm -Uvh http://www.elrepo.org/elrepo-release-7.0-2.el7.elrepo.noarch.rpm && \
#    yum clean packages;

# IUS key/repo, for updated LAMP packages
#RUN wget -q http://dl.iuscommunity.org/pub/ius/IUS-COMMUNITY-GPG-KEY && \
#    gpg2 --import IUS-COMMUNITY-GPG-KEY && \
#    rpm --import IUS-COMMUNITY-GPG-KEY && \
#    rpm -Uvh http://dl.iuscommunity.org/pub/ius/stable/CentOS/7/x86_64/ius-release-1.0-13.ius.centos7.noarch.rpm && \
#    yum clean packages;

# RVM key, for alternative Ruby packages
RUN gpg2 --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3;

# Puppet key/repo, for Puppet packages
RUN wget -q http://yum.puppetlabs.com/RPM-GPG-KEY-puppetlabs && \
    gpg2 --import RPM-GPG-KEY-puppetlabs && \
    rpm --import RPM-GPG-KEY-puppetlabs && \
    rpm -ivh http://yum.puppetlabs.com/puppetlabs-release-el-7.noarch.rpm && \
    yum clean packages;

# Update the PMS cache
RUN yum makecache;

#
# Ruby (via PMS)
#

# Install Ruby 2.0.x
RUN yum -y install ruby ruby-devel rubygems && \
    yum clean packages;

#
# Puppet (via PMS)
#

# Install Puppet 3.7.x
RUN yum -y install puppet && \
    yum clean packages;

#
# Rubygems (via rubygems)
#

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Bundler latest gem
RUN /bin/bash -l -c "gem install bundler";

# Install Puppet latest and Librarian latest (for ruby >=1.9.x) gems
RUN /bin/bash -l -c "gem install librarian-puppet";

#
# RVM and Ruby (via rvm)
#

# Install RVM latest
#RUN curl -L get.rvm.io | bash -s stable;

# Install system dependencies for ruby
#RUN /bin/bash -l -c "rvm requirements" && \
#    yum clean packages;

# Install Ruby 2.0-latest (2.2 not supported in puppet)
#RUN /bin/bash -l -c "rvm install 2.0-latest";

# Set default Ruby interpreter
#RUN /bin/bash -l -c "rvm use 2.0-latest --default";

#
# Rubygems (via rubygems)
#

# Configure Rubygems
#RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Bundler latest gem
#RUN /bin/bash -l -c "gem install bundler";

# Install Puppet latest and Librarian latest (for ruby >=1.9.x) gems
#RUN /bin/bash -l -c "gem install puppet librarian-puppet";

