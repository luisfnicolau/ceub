Entidades fortes:
Pessoas
Produtos


Entidades fracas que dependem somente de entidades fortes:
Tutores
Funcionarios
Enderecos

Outras entidades fracas:
Receitas
Atendentes
Vendas
Medicos
Consultas
Item_venda
Pets
Exames

Pessoas (~~id_pess_PK~~, nome, telefone, email)

Produtos (~~id_prod_PK~~, nome_produto, marca, quantidade, peso, valor, validade)

Tutores (id_tuto_PFK, data_cadastro)
id_tuto_PFK REFERENCIA Pessoas

Funcionarios (id_func_PFK, dataAdmissao, salario, id_chef_FK)
id_func_PFK REFERENCIA Pessoas
id_chef_FK REFERENCIA Funcionarios

Enderecos (id_pess_PFK, rua, numero, bairro, cidade, UF, CEP, complemento)
id_pess_PFK REFERENCIA Pessoas

Pets (id_pets_PK, nome, especie, raca, dataNascimento, sexto, id_tuto_FK)
id_tuto_FK REFERENCIA Tutores

Vendas (id_venda_PK, data_venda, valorTotal, id_aten_FK, id_tuto_FK)
id_aten_FK REFERENCIA 



Consultas (id_cons_PK, dataConsulta, horario, diagnostico, observacoes, id_medi_FK, id_pets_FK, id_aten_FK)
Receitas(id_rece_PK, nome, dosagem, frequencia, id_cons_FK)