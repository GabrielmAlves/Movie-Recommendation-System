import React, { useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, KeyboardAvoidingView, Platform, ScrollView } from 'react-native';
import { useForm, Controller } from 'react-hook-form';
import * as yup from 'yup';
import { yupResolver } from '@hookform/resolvers/yup';
import DropDownPicker from 'react-native-dropdown-picker';

const schema = yup.object({
    name: yup.string().required("Informe seu nome!"),
    username: yup.string().required("Informe seu nome de usuário!"),
    password: yup.string().min(8, "A senha deve ter pelo menos 8 dígitos!").required("Informe sua senha!"),
    email: yup.string().required("Informe seu e-mail!").email("Informe um e-mail válido!")
});

export default function CreateAccountScreen({ navigation }) {
    const { control, handleSubmit, formState: { errors } } = useForm({
        resolver: yupResolver(schema),
        defaultValues: {
            name: '',
            username: '',
            password: '',
            email: ''
        }
    });

    function handleCreateAccount(data) {
        const payload = {
            ...data,
            genres: value
        };
    
        fetch("http:///signup", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(payload)
        })
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao criar conta');
            }
            return response.json();
        })
        .then(result => {
            console.log("Conta criada com sucesso:", result);
        })
        .catch(error => {
            console.error("Erro ao enviar dados:", error);
        });
    }

    const [open, setOpen] = useState(false);
    const [value, setValue] = useState([]);
    const [items, setItems] = useState([
        { label: 'Terror', value: 'terror' },
        { label: 'Ação', value: 'acao' },
        { label: 'Comédia', value: 'comedia' },
        { label: 'Romance', value: 'romance' },
        { label: 'Ficção científica', value: 'ficcao' }
    ]);

    return (
        <KeyboardAvoidingView
            style={{ flex: 1 }}
            behavior={Platform.OS === 'ios' ? 'padding' : undefined}
        >
            <ScrollView
    contentContainerStyle={styles.container}
    keyboardShouldPersistTaps="handled"
>
    <View style={styles.form}>
        <Controller control={control} name='name' render={({ field: { onChange, onBlur, value } }) => (
            <TextInput
                style={[styles.input, errors.name && styles.inputError]}
                onChangeText={onChange}
                onBlur={onBlur}
                value={value}
                placeholder='Digite seu nome'
            />
        )} />

        <Controller control={control} name='username' render={({ field: { onChange, onBlur, value } }) => (
            <TextInput
                style={[styles.input, errors.username && styles.inputError]}
                onChangeText={onChange}
                onBlur={onBlur}
                value={value}
                placeholder='Digite seu nome de usuário'
            />
        )} />

        <Controller control={control} name='password' render={({ field: { onChange, onBlur, value } }) => (
            <TextInput
                style={[styles.input, errors.password && styles.inputError]}
                onChangeText={onChange}
                onBlur={onBlur}
                value={value}
                placeholder='Digite sua senha'
                secureTextEntry
            />
        )} />

        <Controller control={control} name='email' render={({ field: { onChange, onBlur, value } }) => (
            <TextInput
                style={[styles.input, errors.email && styles.inputError]}
                onChangeText={onChange}
                onBlur={onBlur}
                value={value}
                placeholder='Digite seu e-mail'
            />
        )} />
    </View>

    <View style={{ zIndex: 1000, width: '80%', alignSelf: 'center', marginTop: 10 }}>
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
            style={styles.dropdown}
            dropDownContainerStyle={styles.dropdownContainer}
            listMode="SCROLLVIEW" 
            zIndex={3000}
            zIndexInverse={1000}
        />
    </View>

    <TouchableOpacity style={styles.button} onPress={handleSubmit(handleCreateAccount)}>
        <Text style={styles.buttonText}>Criar conta</Text>
    </TouchableOpacity>
</ScrollView>

        </KeyboardAvoidingView>
    );
}

const styles = StyleSheet.create({
    container: {
        flexGrow: 1,
        backgroundColor: '#90B8E0',
        justifyContent: 'center',
        alignItems: 'center',
        paddingBottom: 100,
    },
    form: {
        width: '100%',
        alignItems: 'center'
    },
    input: {
        width: '80%',
        height: 40,
        backgroundColor: '#fff',
        borderRadius: 50,
        fontSize: 15,
        fontWeight: 'bold',
        textAlign: 'left',
        alignSelf: 'center',
        paddingHorizontal: 20,
        marginVertical: 10,
    },
    inputError: {
        borderWidth: 1,
        borderColor: '#ff375b'
    },
    button: {
        backgroundColor: 'red',
        borderRadius: 50,
        paddingVertical: 10,
        width: '60%',
        alignItems: 'center',
        justifyContent: 'center',
        marginTop: 20
    },
    buttonText: {
        fontSize: 18,
        color: "#fff",
        fontWeight: 'bold'
    },
    dropdown: {
        borderRadius: 50
    },
    dropdownContainer: {
        borderRadius: 50
    }
});
