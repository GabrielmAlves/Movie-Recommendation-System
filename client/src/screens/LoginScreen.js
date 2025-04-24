import React, {useState} from 'react';
import { View, Button, Text, StyleSheet, Image, TouchableOpacity, TextInput } from 'react-native';
import { useForm, Controller } from 'react-hook-form'
import * as yup from 'yup'
import { yupResolver } from '@hookform/resolvers/yup'


const schema = yup.object({
  username: yup.string().required("Informe seu nome de usuário!"),
  password: yup.string().min(8, "A senha deve ter pelo menos 8 dígitos!").required("Digite sua senha!")
})

export default function LoginScreen({ navigation }) {
     const {control, handleSubmit, formState:{errors}} = useForm({
        resolver: yupResolver(schema)
     })

     function handleSignIn(data) {
      navigation.navigate('Home')
      console.log(data)
     }

     return (
       <View style={styles.container}>
        <View style={styles.containerLogo}>
          <Image source={require('../../assets/movie-icon.png')}
                 style={{width:'75%'}}
                 resizeMode="contain"/>
        </View>
        
        <View style={styles.containerLoginForm}>
          <Controller control={control} name='username' render={({ field: { onChange, onBlur, value } }) => (
            <TextInput style={[styles.input, 
              { borderWidth: errors.username && 1,
                borderColor: errors.username && 'ff375b'
              }]} 
                       onChangeText={onChange}
                       onBlur={onBlur} 
                       value={value} 
                       placeholder='Nome de usuário'>
            </TextInput>
          )}/>
          {errors.username && <Text style={styles.errorMessage} >{errors.username?.message}</Text>}

          <Controller control={control} name='password' render={({ field: { onChange, onBlur, value}}) => (
            <TextInput style={[styles.input, 
              { borderWidth: errors.password && 1,
                borderColor: errors.password && 'ff375b'
              }]} 
                       onChangeText={onChange} 
                       value={value} 
                       placeholder='Senha'
                       secureTextEntry={true}>
            </TextInput>
          )}/>
          {errors.password && <Text style={styles.errorMessage} >{errors.password?.message}</Text>}


          <TouchableOpacity style={styles.createAccountButton} onPress={() => navigation.navigate('CreateAccount')}>
            <Text style={styles.createAccountText} >Não tem conta? Crie uma!</Text>
          </TouchableOpacity>

          <TouchableOpacity style={styles.button} onPress={handleSubmit(handleSignIn)}>
            <Text style={styles.buttonText}>Entrar</Text>
          </TouchableOpacity>
        </View>

       </View>  
     );
 }

 const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#90B8E0',
  },

  containerLogo: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    width: '100%', // Garantir que ocupe toda a largura disponível
    height: 200,   // Ajuste de altura conforme necessário
  },

  containerLoginForm: {
    flex: 1,
    backgroundColor: '#fff',
    borderTopLeftRadius: 25,
    borderTopRightRadius: 25,
    paddingStart: '5%',
    paddingEnd: '5%',
  },

  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginTop: 28,
    marginBottom: 12,
  },

  text: {
    color: "a1a1a1"
  },

  button: {
    position: 'absolute',
    backgroundColor: 'red',
    borderRadius: 50,
    paddingVertical: 8,
    width: '60%',
    alignSelf: 'center',
    bottom: '15%',
    alignItems: 'center',
    justifyContent: 'center'
  },

  buttonText: {
    fontSize: 18,
    color: "#fff",
    fontWeight: 'bold'
  },

  input: {
    width: '100%',
    height: 40,
    backgroundColor: '#90B8E0',
    top: 70,
    borderRadius: 50,
    fontSize: 15,
    fontWeight: 'bold',
    textAlign: 'left',
    padding: 20,
    marginBottom: 20
  },

  errorMessage: {
    alignSelf: 'flex-start',
    color: '#ff375b',
    marginBottom: 20,
    marginTop: 60
  },

  createAccountText: {
    fontSize: 18,
    color: "black",
    fontWeight: 'light'
  },

  createAccountButton: {
    position: 'relative',
    paddingVertical: 8,
    width: '60%',
    alignSelf: 'right',
    bottom: '-12%',
    alignItems: 'right',
    justifyContent: 'right'
  }
})
