import React, {useState} from 'react';
import { View, Button, Text, StyleSheet, Image, TouchableOpacity, TextInput } from 'react-native';
import { useForm, Controller } from 'react-hook-form'
import * as yup from 'yup'
import { yupResolver } from '@hookform/resolvers/yup'
import DropDownPicker from 'react-native-dropdown-picker';

export default function CreateAccountScreen ({ navigation }) {
     const {control, handleSubmit, formState:{errors}} = useForm({
            
         })

         const [open, setOpen] = useState(false);
         const [value, setValue] = useState(null);
         const [items, setItems] = useState([
           {label: 'Terror', value: 'terror'},
           {label: 'Ação', value: 'acao'},
           {label: 'Comédia', value: 'comedia'},
         ]);     
    return (
        
        <View style={styles.container}>
            <View>
                <Controller control={control} name='name' render={({ field: { onChange, onBlur, value }}) => (
                        <TextInput style={[styles.input, 
                                    { borderWidth: errors.name && 1,
                                        borderColor: errors.name && 'ff375b'
                                    }]} 
                                            onChangeText={onChange}
                                            onBlur={onBlur} 
                                            value={value} 
                                            placeholder='Digite seu nome'>
                        </TextInput>
                )}/>

                <Controller control={control} name='username' render={({ field: { onChange, onBlur, value }}) => (
                        <TextInput style={[styles.input, 
                                    { borderWidth: errors.username && 1,
                                        borderColor: errors.username && 'ff375b'
                                    }]} 
                                    onChangeText={onChange}
                                    onBlur={onBlur} 
                                    value={value} 
                                    placeholder='Digite seu nome de usuário'>
                        </TextInput>
                )}/>

                <Controller control={control} name='password' render={({ field: { onChange, onBlur, value }}) => (
                        <TextInput style={[styles.input, 
                                    { borderWidth: errors.password && 1,
                                        borderColor: errors.password && 'ff375b'
                                    }]} 
                                    onChangeText={onChange}
                                    onBlur={onBlur} 
                                    value={value} 
                                    placeholder='Digite sua senha'
                                    secureTextEntry={true}>
                        </TextInput>
                )}/>

                <Controller control={control} name='email' render={({ field: { onChange, onBlur, value }}) => (
                        <TextInput style={[styles.input, 
                                    { borderWidth: errors.email && 1,
                                        borderColor: errors.email && 'ff375b'
                                    }]} 
                                    onChangeText={onChange}
                                    onBlur={onBlur} 
                                    value={value} 
                                    placeholder='Digite seu e-mail'
                                    secureTextEntry={true}>
                        </TextInput>
                )}/>

                <DropDownPicker
                    multiple={true}
                    mode='BADGE'
                    open={open}
                    value={value}
                    items={items}
                    setOpen={setOpen}
                    setValue={setValue}
                    setItems={setItems}
                    placeholder="Seus gêneros de filme preferidos"
                    dropDownDirection="BOTTOM"
                    style={styles.dropdown}
                    dropDownContainerStyle={styles.dropdown}
                    zIndex={3000}
                    zIndexInverse={1000}
                    />
            </View>
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
      flex: 1,
      backgroundColor: '#90B8E0',
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
      width: '80%',
      height: 40,
      backgroundColor: '#fff',
      top: 150,
      borderRadius: 50,
      fontSize: 15,
      fontWeight: 'bold',
      textAlign: 'left',
      alignItems: 'center',
      justifyContent: 'center',
      alignSelf: 'center',
      padding: 10,
      margin: 20,
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
    },

    dropdown: {
        width: '80%',
        margin: 170,
        alignSelf: 'center',
        borderRadius: 50,
        zIndex: 1000
    }
 })