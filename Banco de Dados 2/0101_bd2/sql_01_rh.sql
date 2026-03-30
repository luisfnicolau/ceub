create database bd_revisao_0101;
use bd_revisao_0101;

create table tb_cliente
(
cd_cliente int not null primary key,
cliente varchar(50)
);

create table tb_vendedor
(
cd_vendedor int not null primary key,
vendedor varchar(50)
);

create table tb_veiculo
(
cd_veiculo int not null primary key,
veiculo char(50),
valor_veiculo decimal(12,2)
);

create table tb_pedido(
dt_pedido date not null,
cd_veiculo int not null,
cd_vendedor int not null,
cd_cliente int not null,
nr_pedido int,
valor_pedido decimal (12,2),
comissao decimal (12,2),
primary key (dt_pedido, cd_veiculo, cd_vendedor, cd_cliente)
);

alter table tb_pedido
add constraint fk_cliente foreign key (cd_cliente)
references tb_cliente(cd_cliente);

alter table tb_pedido
add constraint fk_vendedor foreign key (cd_vendedor)
references tb_vendedor(cd_vendedor);

alter table tb_pedido
add constraint fk_veiculo foreign key (cd_veiculo)
references tb_veiculo(cd_veiculo);