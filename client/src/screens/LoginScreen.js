import React, {useState} from 'react';
import { View, Button, Text, StyleSheet, Image, TouchableOpacity, TextInput } from 'react-native';
import { useForm, Controller } from 'react-hook-form'
 
 export default function LoginScreen({ navigation }) {
     const {control, handleSubmit, formState:{errors}} = useForm({

     })

     function handleSignIn(data) {
      alert(data)
     }
     const [username, setUsername] = useState('')
     const [password, setPassword] = useState('')

     return (
       <View style={styles.container}>
        <View style={styles.containerLogo}>
          <Image source={require('../../assets/movie-icon.png')}
                 style={{width:'100%'}}
                 resizeMode="contain"/>
        </View>
        
        <View style={styles.containerLoginForm}>
          <Controller control={control} name='username' render={() => (
            <TextInput style={styles.input} 
                       onChangeText={setUsername} 
                       value={username} 
                       placeholder='Nome de usuário'>
            </TextInput>
          )}/>

          
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
      backgroundColor: '#90B8E0',
      justifyContent: 'center',
      alignItems: 'center',
      width: 270,
      height: 200,
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
      backgroundColor: 'grey',
      top: 100,
    }
 })