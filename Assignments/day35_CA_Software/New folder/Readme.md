curl -LO https://storage.googleapis.com/kubernetes-release/release/`curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt`/bin/linux/amd64/kubectl

chmod +x kubectl
sudo mv kubectl /usr/local/bin/


############################

kubectl version --client

############################

curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64

chmod +x minikube-linux-amd64
sudo mv minikube-linux-amd64 /usr/local/bin/minikube

##############################

minikube version

#################################

minikube start --driver=docker

###############################

kubectl get nodes

###############################

eval $(minikube docker-env)

###############################

docker build -t cpp-microservice .

##############################

docker images

############################

kubectl apply -f deployment.yaml

#############################

kubectl get deployments
kubectl get pods

###############################

kubectl apply -f service.yaml

################################

kubectl get services

################################

minikube service cpp-microservice-service

################################

curl $(minikube service cpp-microservice-service --url)

##################################

